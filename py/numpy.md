## numpy
`numpy.ndarray`
  - 2-dimensional array
  - items can be fetched using the syntax `a[i, j]`
  - arrays can be sliced with syntax `a[m:n, k:l]`
  - FP:35
`numpy.arange(n)` build a `numpy.ndarray` object with numbers 0 to n-1 (FP:52)
`numpy.loadtxt(filename)` load numbers stored in a text file (FP:53)
## pandas
summary: open-source Python library used for data science
operation: runs over NumPy
`import pandas`
`df=pandas.DataFrame()`
  - `DataFrame` is the main object in `pandas`
  - good for storing lists-of-lists (CSV)
`print(df)`
  - prints it out in an easy to read tabular format
### DataFrame methods
  - `head()`, `tail()`
    - prints out the first, last several rows (5 by default)
    - optional numerical argument defines number of rows
  - `describe()`
    - numerical analyses, including count, unique, mean, etc
  - `sort_values('field',ascending=False)`
