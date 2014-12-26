import random

f = open('data.xml', 'w')
f.write("""<note>""")
for x in range(0, 259):
    print "<"+str(x)+">"+str(random.randint(10,100))+"</"+str(x)+">"
    f.write("<"+str(x)+">"+str(random.randint(10,100))+"</"+str(x)+">")
f.write("</note>")
f.close()
