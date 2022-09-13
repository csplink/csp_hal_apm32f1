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
    def generate(path):
        tree = Et.parse(path)
        root = tree.getroot()
        rects = []
        width = 0
        height = 0
        for item in root.iter():
            if item.tag.lower().endswith("svg"):
                width = float(item.attrib["width"].replace("px", ""))
                height = float(item.attrib["height"].replace("px", ""))
            elif item.tag.lower().endswith("rect") and "ff0000" in item.attrib["stroke"].lower():
                rects.append(Rect(item.attrib["x"], item.attrib["y"], item.attrib["width"], item.attrib["height"]))
        rects.sort(key=lambda x: (x.x, x.y))
        xml_rects = Et.Element('Rects', width=str(width), height=str(height))
        i = 0
        for item in rects:
            i += 1
            Et.SubElement(xml_rects, 'Rect', id=str(i), x=str(item.x), y=str(item.y), width=str(item.width),
                          height=str(item.height))
        dom = minidom.parseString(Et.tostring(xml_rects))
        file_path, file_name = os.path.split(path)
        file_path = file_path + "/" + os.path.splitext(file_name)[0] + ".xml"
        print("generate: " + file_path)
        with open(file_path, 'w') as f:
            dom.writexml(f, "", "    ", "\n", "utf-8")


if __name__ == "__main__":
    Svg.generate(
        r"D:\Users\xqyjlj\Documents\git\github\xqyjlj\csp_hal_apm32f1\description\apm32f103zet6\clock\apm32f103zet6.svg")
