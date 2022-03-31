# Bullet

**`bullet.Check()`** implements a checkbox widget:
```py
cli = bullet.Check(prompt = "Choose from the following items: ", choices=['pepperoni','sausage','green peppers'])
```
**`bullet.Bullet()`** implements a radio button widget:
```py
cli = bullet.Bullet(prompt = "Choose from the following items: ", choices=['red','white','blue'])
```
The resulting object then exposes a **`launch()`** method.
```py
cli.launch()
```
