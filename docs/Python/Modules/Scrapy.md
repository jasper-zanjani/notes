# scrapy

Best used to obtain one "stream" of data at a time, without trying to obtain data from different pages
```sh
scrapy runspider spider.py -o file.json
```
Display HTML source of the scraped page
```python
print(response.txt)
```
Get `{URL}`
```python
fetch('url')
```
Select a CSS selector
```python
# Returns a `SelectorList`
response.css('p')
# Retrieve full HTML elements
response.css('p').extract()
```
Retrieve only the text within the element
```python
response.css('p::text').extract()
response.css('p::text').extract_first()
response.css('p::text').extract()[0]
```
Get the `href` attribute value for an anchor tag
```python
response.css('a').attrib['href']
```
Launch Scrapy shell and scrape `$URL`
```bash
scrapy shell $URL
```
Make a default spider named {quotes} that will be restricted to {domain}
```python
scrapy genspider quotes domain
```
```python
scrapy runspider scrapy1.py
```
Run a spider, saving scraped data to a JSON file
```python
scrapy runspider spider.py -o items.json
``` 
Method which contains most of the logic of the spider, especially after the `yield` keyword. For multiple items, a structural basis for iteration must be found and for each iteration, data is yielded

Extract URL from link using standard CSS selection techniques

Add the domain name to a relative link
```python
response.urljoin()
```
Recursively call the `parse` method again on the next page
```python
yield scrapy.Request(url=next_page_url, callback=self.parse)
``` 
Scrape detail pages
  - `parse_details` would be a spider method _sibling_ to the main `parse` method
  - if a detail page has more information than the main, then the `yield` keyword should be in `parse_details`
```python
yield scrapy.Request(url={url}, callback=self.parse_details)
```