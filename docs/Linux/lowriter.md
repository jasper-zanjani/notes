`lowriter` is a command-line utility installed with LibreOffice Writer. ([src](https://vitux.com/how-to-convert-documents-to-pdf-format-on-the-ubuntu-command-line/ "vitux.com: \"How to convert documents to PDF format on the Ubuntu Command Line\""))

Convert a single file to PDF
```sh
lowriter --convert-to pdf filename.doc
```
Convert a batch of files using globbing
```sh
lowriter --convert-to pdf *.docx
```