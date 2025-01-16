
if __name__ == '__main__':
  fileName = "XXX"
  fileName = fileName.upper()
  s = "#ifndef _{}_H_\n" \
      "#define _{}_H_\n\n" \
      "namespace syfmt {{\n" \
      "namespace details {{\n\n" \
      "}} // namespace details\n" \
      "}} // namespace syfmt\n\n" \
      "#endif // _{}_H_\n".format(fileName, fileName, fileName)

  f = open("include/{}.{}".format(fileName, "h"), "w+")
  f.write(s)
  f.close()

  f = open("src/{}.{}".format(fileName, "cpp"), "w+")
  f.write(s)
  f.close()

