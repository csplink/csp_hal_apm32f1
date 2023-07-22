#include <clink/libc.h>

CLINK_WEAK void *clink_memset(void *s, int c, size_t count)
{
#ifdef CLINK_USING_TINY_SIZE
    char *xs = (char *)s;

    while (count--)
        *xs++ = c;

    return s;
#else
#define LBLOCKSIZE     (sizeof(size_t))
#define UNALIGNED(X)   ((long)X & (LBLOCKSIZE - 1))
#define TOO_SMALL(LEN) ((LEN) < LBLOCKSIZE)
    unsigned int   i            = 0;
    char          *m            = (char *)s;
    unsigned long  buffer       = 0;
    unsigned long *aligned_addr = CLINK_NULL;
    unsigned char  d =
        (unsigned int)c & (unsigned char)(-1); /* To avoid sign extension, copy C to an
                 unsigned variable. (unsigned)((char)(-1))=0xFF for 8bit and =0xFFFF for 16bit: word independent */

    if (!TOO_SMALL(count) && !UNALIGNED(s))
    {
        /* If we get this far, we know that count is large and s is word-aligned. */
        aligned_addr = (unsigned long *)s;

        /* Store d into each char sized location in buffer so that
         * we can set large blocks quickly.
         */
        for (i = 0; i < LBLOCKSIZE; i++)
        {
            *(((unsigned char *)&buffer) + i) = d;
        }

        while (count >= LBLOCKSIZE * 4)
        {
            *aligned_addr++ = buffer;
            *aligned_addr++ = buffer;
            *aligned_addr++ = buffer;
            *aligned_addr++ = buffer;
            count -= 4 * LBLOCKSIZE;
        }

        while (count >= LBLOCKSIZE)
        {
            *aligned_addr++ = buffer;
            count -= LBLOCKSIZE;
        }

        /* Pick up the remainder with a bytewise loop. */
        m = (char *)aligned_addr;
    }

    while (count--)
    {
        *m++ = (char)d;
    }

    return s;

#undef LBLOCKSIZE
#undef UNALIGNED
#undef TOO_SMALL
#endif
}

CLINK_WEAK void *clink_memcpy(void *dst, const void *src, size_t count)
{
#ifdef CLINK_USING_TINY_SIZE
    char      *tmp = (char *)dst, *s = (char *)src;
    rt_ubase_t len = 0;

    if (tmp <= s || tmp > (s + count))
    {
        while (count--)
            *tmp++ = *s++;
    }
    else
    {
        for (len = count; len > 0; len--)
            tmp[len - 1] = s[len - 1];
    }

    return dst;
#else
#define UNALIGNED(X, Y) (((long)X & (sizeof(long) - 1)) | ((long)Y & (sizeof(long) - 1)))
#define BIGBLOCKSIZE    (sizeof(long) << 2)
#define LITTLEBLOCKSIZE (sizeof(long))
#define TOO_SMALL(LEN)  ((LEN) < BIGBLOCKSIZE)
    char  *dst_ptr     = (char *)dst;
    char  *src_ptr     = (char *)src;
    long  *aligned_dst = CLINK_NULL;
    long  *aligned_src = CLINK_NULL;
    size_t len         = count;

    /* If the size is small, or either SRC or DST is unaligned,
    then punt into the byte copy loop.  This should be rare. */
    if (!TOO_SMALL(len) && !UNALIGNED(src_ptr, dst_ptr))
    {
        aligned_dst = (long *)dst_ptr;
        aligned_src = (long *)src_ptr;

        /* Copy 4X long words at a time if possible. */
        while (len >= BIGBLOCKSIZE)
        {
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            len -= BIGBLOCKSIZE;
        }

        /* Copy one long word at a time if possible. */
        while (len >= LITTLEBLOCKSIZE)
        {
            *aligned_dst++ = *aligned_src++;
            len -= LITTLEBLOCKSIZE;
        }

        /* Pick up any residual with a byte copier. */
        dst_ptr = (char *)aligned_dst;
        src_ptr = (char *)aligned_src;
    }

    while (len--)
        *dst_ptr++ = *src_ptr++;

    return dst;
#undef UNALIGNED
#undef BIGBLOCKSIZE
#undef LITTLEBLOCKSIZE
#undef TOO_SMALL
#endif
}

CLINK_WEAK void *clink_memmove(void *dest, const void *src, size_t n)
{
    char *tmp = (char *)dest, *s = (char *)src;

    if (s < tmp && tmp < s + n)
    {
        tmp += n;
        s += n;

        while (n--)
            *(--tmp) = *(--s);
    }
    else
    {
        while (n--)
            *tmp++ = *s++;
    }

    return dest;
}

CLINK_WEAK int clink_memcmp(const void *cs, const void *ct, size_t count)
{
    const unsigned char *su1 = CLINK_NULL, *su2 = CLINK_NULL;
    int                  res = 0;

    for (su1 = (const unsigned char *)cs, su2 = (const unsigned char *)ct; 0 < count; ++su1, ++su2, count--)
        if ((res = *su1 - *su2) != 0)
            break;

    return res;
}

CLINK_WEAK char *clink_strstr(const char *s1, const char *s2)
{
    int l1 = 0, l2 = 0;

    l2 = clink_strlen(s2);
    if (!l2)
    {
        return (char *)s1;
    }

    l1 = clink_strlen(s1);
    while (l1 >= l2)
    {
        l1--;
        if (!clink_memcmp(s1, s2, l2))
        {
            return (char *)s1;
        }

        s1++;
    }

    return CLINK_NULL;
}

CLINK_WEAK int clink_strcasecmp(const char *a, const char *b)
{
    int ca = 0, cb = 0;

    do
    {
        ca = *a++ & 0xff;
        cb = *b++ & 0xff;
        if (ca >= 'A' && ca <= 'Z')
            ca += 'a' - 'A';
        if (cb >= 'A' && cb <= 'Z')
            cb += 'a' - 'A';
    } while (ca == cb && ca != '\0');

    return ca - cb;
}

CLINK_WEAK char *clink_strncpy(char *dst, const char *src, size_t n)
{
    if (n != 0)
    {
        char       *d = dst;
        const char *s = src;

        do
        {
            if ((*d++ = *s++) == 0)
            {
                /* NUL pad the remaining n-1 bytes */
                while (--n != 0)
                {
                    *d++ = 0;
                }

                break;
            }
        } while (--n != 0);
    }

    return (dst);
}

CLINK_WEAK char *clink_strcpy(char *dst, const char *src)
{
    char *dest = dst;

    while (*src != '\0')
    {
        *dst = *src;
        dst++;
        src++;
    }

    *dst = '\0';
    return dest;
}

CLINK_WEAK int clink_strncmp(const char *cs, const char *ct, size_t count)
{
    signed char __res = 0;

    while (count)
    {
        if ((__res = *cs - *ct++) != 0 || !*cs++)
        {
            break;
        }

        count--;
    }

    return __res;
}

CLINK_WEAK int clink_strcmp(const char *cs, const char *ct)
{
    while (*cs && *cs == *ct)
    {
        cs++;
        ct++;
    }

    return (*cs - *ct);
}

CLINK_WEAK size_t clink_strlen(const char *s)
{
    const char *sc = CLINK_NULL;

    for (sc = s; *sc != '\0'; ++sc) /* nothing */
        ;

    return sc - s;
}

CLINK_WEAK size_t clink_strnlen(const char *s, size_t maxlen)
{
    const char *sc;

    for (sc = s; *sc != '\0' && (size_t)(sc - s) < maxlen; ++sc) /* nothing */
        ;

    return sc - s;
}
