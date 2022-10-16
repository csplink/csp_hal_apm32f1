import os
import xml.etree.ElementTree as Et


class Rect:
    x = 0
    y = 0
    width = 0
    height = 0

    def __init__(self, x, y, width, height):
        self.x = float(x) - 0.5
        self.y = float(y) - 0.5
        self.width = float(width) + 1
        self.height = float(height) + 1


class Ellipse:
    x = 0
    y = 0
    width = 0
    height = 0

    def __init__(self, x, y, width, height):
        self.x = float(x) - float(width) - 1.6
        self.y = float(y) - float(height) - 1.8
        self.width = (float(width) + 2) * 2
        self.height = (float(height) + 2) * 2


class Svg:
    @staticmethod
    def indent(elem, level=0):
        i = "\n" + level * "    "
        if len(elem):
            if not elem.text or not elem.text.strip():
                elem.text = i + "    "
            if not elem.tail or not elem.tail.strip():
                elem.tail = i
            for elem in elem:
                Svg.indent(elem, level + 1)
            if not elem.tail or not elem.tail.strip():
                elem.tail = i
        else:
            if level and (not elem.tail or not elem.tail.strip()):
                elem.tail = i

    @staticmethod
    def generate_xml(file, width, height, rects, ellipses):
        xml_clock = Et.Element('Clock', Width=str(width), Height=str(height))

        xml_rects = Et.SubElement(xml_clock, 'Rects')
        i = 0
        for item in rects:
            i += 1
            Et.SubElement(xml_rects, 'Rect', ID=str(i), X=str(item.x), Y=str(item.y), Width=str(item.width),
                          Height=str(item.height))

        xml_rects = Et.SubElement(xml_clock, 'Ellipses')
        for item in ellipses:
            i += 1
            Et.SubElement(xml_rects, 'Ellipse', ID=str(i), X=str(item.x), Y=str(item.y), Width=str(item.width),
                          Height=str(item.height))

        Svg.indent(xml_clock)
        with open(file, 'wb') as f:
            data = Et.tostring(xml_clock, encoding="utf-8", xml_declaration=True)
            if data[-1] == b'\n'[0]:
                f.write(data[0:len(data) - 1])
            else:
                f.write(data)

    @staticmethod
    def change_xml(file, width, height, rects, ellipses):
        xml_tree = Et.parse(file)
        xml_root = xml_tree.getroot()

        if "Width" in xml_root.attrib.keys() and "Height" in xml_root.attrib.keys():
            xml_root.attrib["Width"] = str(width)
            xml_root.attrib["Height"] = str(height)

        # 只删除Rects与Ellipses节点
        rect_nodes = xml_root.findall("Rects")
        for node in rect_nodes:
            xml_root.remove(node)
        ellipse_nodes = xml_root.findall("Ellipses")
        for node in ellipse_nodes:
            xml_root.remove(node)

        xml_rects = Et.Element('Rects')
        i = 0
        for item in rects:
            i += 1
            Et.SubElement(xml_rects, 'Rect', ID=str(i), X=str(item.x), Y=str(item.y), Width=str(item.width),
                          Height=str(item.height))
        xml_root.append(xml_rects)

        xml_ellipses = Et.Element('Ellipses')
        for item in ellipses:
            i += 1
            Et.SubElement(xml_ellipses, 'Ellipse', ID=str(i), X=str(item.x), Y=str(item.y), Width=str(item.width),
                          Height=str(item.height))
        xml_root.append(xml_ellipses)

        Svg.indent(xml_root)
        with open(file, 'wb') as f:
            data = Et.tostring(xml_root, encoding="utf-8", xml_declaration=True)
            if data[-1] == b'\n'[0]:
                f.write(data[0:len(data) - 1])
            else:
                f.write(data)

    @staticmethod
    def parse_svg(file):
        rects = []
        ellipses = []
        width = 0
        height = 0

        svg_tree = Et.parse(file)
        svg_root = svg_tree.getroot()
        for item in svg_root.iter():
            if item.tag.lower().endswith("svg"):
                width = float(item.attrib["width"].replace("px", ""))
                height = float(item.attrib["height"].replace("px", ""))
            # rx 和 ry 为圆角矩形的半径
            elif item.tag.lower().endswith("rect") \
                    and "rx" not in item.attrib.keys() \
                    and "ry" not in item.attrib.keys():
                if "stroke-width" not in item.attrib.keys():  # stroke-width 代表外框线宽，为空默认就为1，我们只匹配线宽1的矩形
                    rects.append(Rect(item.attrib["x"], item.attrib["y"], item.attrib["width"], item.attrib["height"]))
                else:
                    if item.attrib["stroke-width"] == "1":
                        rects.append(
                            Rect(item.attrib["x"], item.attrib["y"], item.attrib["width"], item.attrib["height"]))
            # rx 和 ry 为的半径
            elif item.tag.lower().endswith("ellipse"):
                if item.attrib["rx"] == item.attrib["ry"]:
                    if float(item.attrib["rx"]) >= 5:
                        ellipses.append(
                            Ellipse(item.attrib["cx"], item.attrib["cy"], item.attrib["rx"], item.attrib["ry"]))
            rects.sort(key=lambda x: (x.x, x.y))  # 按坐标重排控件
            ellipses.sort(key=lambda x: (x.x, x.y))  # 按坐标重排控件
        return width, height, rects, ellipses

    @staticmethod
    def generate(file):
        width, height, rects, ellipses = Svg.parse_svg(file)  # 解析svg文件
        # 获取xml路径
        file_path, file_name = os.path.split(file)
        xml_path = file_path + "/" + os.path.splitext(file_name)[0] + ".xml"

        # 不存在则直接新建一个
        if not os.path.exists(xml_path):
            Svg.generate_xml(xml_path, width, height, rects, ellipses)
        else:
            Svg.change_xml(xml_path, width, height, rects, ellipses)

        print("generate: " + xml_path)


if __name__ == "__main__":
    description_path = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
    for name in os.listdir(description_path):
        path = description_path + "/" + name + "/clock/" + name + ".svg"
        if os.path.exists(path):
            Svg.generate(path)
