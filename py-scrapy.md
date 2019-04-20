# Scrapy
Best used to obtain one "stream" of data at a time, without trying to obtain data from different pages
`scrapy runspider spider.py -o file.json`
## Scrapy shell
`print(response.txt)`
  print out the HTML source
`fetch('<url>')`
  fetch a URL
## Selectors
`response.css('p')` 
  select a CSS selector, returning a SelectorList
`response.css('p').extract()`
  retrieve full HTML elements
`response.css('p::text').extract()`
  retrieve only the text within the element
`response.css('p::text').extract_first()`
  equivalent to `response.css('p::text').extract()[0]`
`response.css('a').attrib['href']`
  get the 'href' attribute value for an anchor tag
## Command-line
`scrapy shell {url}` 
  launch Scrapy shell where `{url}` is the URL to be scraped
`scrapy genspider quotes toscrape.com` 
  make a spider named 'quotes' that will be restricted to the domain 'toscrape.com
`scrapy runspider scrapy1.py` 
  run the spider 'scrapy1.py'
`scrapy runspider scrapy1.py -o items.json` 
  save the resulting dictionary to a JSON file
## Spiders
`parse`
  - method which contains most of the logic of the spider, especially after the `yield` keyword
  - for multiple items, a structural basis for iteration must be found and for each iteration, data is yielded
## Pagination
Extract URL from link using standard CSS selection techniques
`response.urljoin()` 
  will add the domain name to the link appropriately
`yield scrapy.Request(url=next_page_url, callback=self.parse)` 
  will recursively call the `parse` method again on the next page
## Detail pages
`yield scrapy.Request(url={url}, callback=self.parse_details`
  - `parse_details` would be a spider method _sibling_ to the main `parse` method
  - if a detail page has more information than the main, then the `yield` keyword should be in `parse_details`
  -
