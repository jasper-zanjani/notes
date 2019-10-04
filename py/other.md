# Libraries and packages
#### setuptools
set of enhancements to `distutils` that facilitates the building and distribution of Python packages
`setuptools.setup`

#### PyPDF2
```py
with open(filename,'rb') as f:
  original = PdfFileReader(f)
  out=PdfFileWriter()
  p = original.getPage(x)
```
