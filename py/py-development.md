# Python development fundamentals
Modules to study:
- [ ] __configparser__
- [x] __curses__

## castero
### \_\_init\_\_.py
Metadata variables assigned at top, all surrounded by double-underscores (perhaps intended for use by pip):
  - title
  - description
  - author
  - version
  - date
  - copyright
  - license
  - url
  - help : format string interpolating the variables defined above

Interestingly, the latest version mixes f-string style and %-style template placeholders, with only the %-style ones actually interpolated. The f-string style ones must be interpolated later on...

### \_\_main\_\_.py
imports objects from __castero.display__, __castero.config__, __castero.feeds__
contains main loop: __display.loop()__, where display is an object initialized from __Config()__ and __Feeds()__. The current version of this file imports many more libraries and modules

### config.py
imports __configparser__, as well as __castero.datafile__
the __Config()__ classis read from the configuration file at start

### episode.py
__Episode__ class represents a single podcast episode, basically a collection of the metadata of the variables used to construct it, each of which has a getter method.

### feed.py
imports __requests__, __xml.etree.ElementTree__ as well as __castero.episode__
defines various error classes, as well as the __Feed__ class
ElementTree is used to parse the XML returned from the requests object (`r = requests.get(self._url)`, then `self._tree = ElementTree.fromstring(r.text)`. The validation method depends on this same parsed tree of the XML (`root_children = self._tree.getchildren()`). This method appears to make use of many nested conditionals, perhaps it could be cleaned up? Assertion statements?

### feeds.py
imports from __castero.datafile__, __castero.feed__, and __castero.episode__
Defines the __Feeds__ class, a subclass of __DataFile__, a dictionary-like object which stores information about the user's feeds. It also calls DataFile's constructor, so I have to come back to this one after studying DataFile

### helpers.py
defines a couple of simple functions: __third()__ which returns one third of the argument (with no data validation), and __median()__ which returns the median of a list of integers or floats

## menu.py
Imports __curses__ and defines __Menu__ class

## player.py
Imports __vlc__

## queue.py
