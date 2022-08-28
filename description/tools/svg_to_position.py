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
        for item in root.iter():
            if "rect" in item.tag and "ff0000" in item.attrib["stroke"].lower():
                rects.append(Rect(item.attrib["x"], item.attrib["y"], item.attrib["width"], item.attrib["height"]))
        rects.sort(key=lambda x: (x.x, x.y))
        xml_rects = Et.Element('Rects')
        i = 0
        for item in rects:
            i += 1
            Et.SubElement(xml_rects, 'Rect', id=str(i), x=str(item.x), y=str(item.y), width=str(item.width),
                          height=str(item.height))
        dom = minidom.parseString(Et.tostring(xml_rects))
        file_path, file_name = os.path.split(path)
        rst_path = os.path.relpath(file_path, os.path.join(__file__, "../.."))

        file_path, _ = os.path.split(__file__)
        dest = os.path.abspath(file_path + "/../build/" + rst_path + "/" + os.path.splitext(file_name)[0] + "-Rect.xml")

        file_path, _ = os.path.split(dest)
        if not os.path.exists(file_path):
            os.makedirs(file_path)
        print("generate: " + dest)
        with open(dest, 'w') as f:
            dom.writexml(f, "", "    ", "\n", "utf-8")


if __name__ == "__main__":
    Svg.generate(r"D:\Users\xqyjlj\Documents\git\github\xqyjlj\csp_mcu_db\Company\Geehy\Clock\APM32F103.svg")
