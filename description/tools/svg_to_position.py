import os
import xml.etree.ElementTree as Et
from xml.dom import minidom


class Rect:
    x = 0
    y = 0
    width = 0
    height = 0

    def __init__(self, x, y, width, height):
        self.x = float(x) - 1
        self.y = float(y) - 1
        self.width = float(width)
        self.height = float(height)


class Svg:
    @staticmethod
    def generate_xml(file, width, height, rects):
        xml_clock = Et.Element('Clock')
        xml_rects = Et.SubElement(xml_clock, 'Rects', Width=str(width), Height=str(height))
        i = 0
        for item in rects:
            i += 1
            Et.SubElement(xml_rects, 'Rect', ID=str(i), X=str(item.x), Y=str(item.y), Width=str(item.width),
                          Height=str(item.height))
        dom = minidom.parseString(Et.tostring(xml_clock))

        with open(file, 'w') as f:
            dom.writexml(f, "", "    ", "\n", "utf-8")

    @staticmethod
    def parse_svg(file):
        rects = []
        width = 0
        height = 0

        svg_tree = Et.parse(file)
        svg_root = svg_tree.getroot()
        for item in svg_root.iter():
            if item.tag.lower().endswith("svg"):
                width = float(item.attrib["width"].replace("px", ""))
                height = float(item.attrib["height"].replace("px", ""))
            elif item.tag.lower().endswith("rect") and "ff0000" in item.attrib["stroke"].lower():
                rects.append(Rect(item.attrib["x"], item.attrib["y"], item.attrib["width"], item.attrib["height"]))
        rects.sort(key=lambda x: (x.x, x.y))  # 按坐标重排控件
        return width, height, rects

    @staticmethod
    def generate(file):
        width, height, rects = Svg.parse_svg(file)  # 解析svg文件
        # 获取xml路径
        file_path, file_name = os.path.split(file)
        xml_path = file_path + "/" + os.path.splitext(file_name)[0] + ".xml"

        # 不存在则直接新建一个
        if not os.path.exists(xml_path):
            Svg.generate_xml(xml_path, width, height, rects)
        else:
            print("generate: " + xml_path)

        print("generate: " + xml_path)


if __name__ == "__main__":
    description_path = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
    for name in os.listdir(description_path):
        path = description_path + "/" + name + "/clock/" + name + ".svg"
        if os.path.exists(path):
            Svg.generate(path)
