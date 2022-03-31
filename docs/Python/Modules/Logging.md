# Logging

```python
import logging

def main():
    logging.basicConfig(filename='/tmp/learn-logging.log', level=logging.ERROR, format='%(asctime)s %(levelname)s: %(message)s')
    logging.info("Once upon a midnight dreary,")
    logging.warning('While I pondered weak and weary,')
    logging.error('Over many a quaint and curious volume of forgotten lore,')

if __name__ == '__main__':
    main()
```