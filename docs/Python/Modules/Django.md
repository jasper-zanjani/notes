# Django

A typical Django **project** contains multiple **apps**, which are Python packages containing their own models, views, templates, and urls.

- A [**model**](#models) is the single definitive source of information about your data, and contains the essential fields and behaviors of the data you're storing. 
- **Migrations** are necessary when Model classes are updated. And for projects sufficiently advanced, migration scripts must be developed for any such changes.

- **Async Server Gateway Interface (ASGI)** is the spiritual successor to, and superset of, [**WSGI**](#wsgi). It implements the new Python standard for asynchronous web servers and applications, which resembles that of [websockets](#sockets). :point_right: [From WSGI to ASGI](https://youtu.be/IhF2JwyH664)
- **WSGI** is coupled tightly with the synchronous request-response model familiar from HTTP 1.1.

URL patterns (stored in the `urlpatterns` list defined in the project-level **urls.py** file) can be parameterized. Here, the template `<int:x>` specifies an integer to be assigned to the view parameter `x`.
```py
from app.views import my_view

urlpatterns = [
  path('/example/<int:x>', my_view)
]
```
`modelform_factory` can be used to automatically produce a webform from a Model class.
```py
# views.py

MeetingForm = modelform_factory(Meeting, exclude=[])
```
This can be placed into a template using the `{{ form }}` template tag. Note, a `{% csrf_token %}` template tag must also be present for a submit button to work.
```py
{% block content %}
<h1>Plan a new meeting</h1>
<form method="POST">
  <table>
    {{form}}
  </table>
  {% csrf_token %}
  <button type="submit">Create</button>
</form>
{% endblock content %}
```
When the `modelform_factory` class has been defined, it is instantiated within the **view function**. This object exposes several methods:
- **is_valid** data validation is strongly recommended for any form input
- **save** imports the validated form data into the database
```py
def new(request):
  if request.method == 'POST':
    form = MeetingForm(request.POST)
    if form.is_valid():
      form.save()
      return redirect("home")
  else:
    form = MeetingForm()
  
  return render(request, "meetings/new.html", {"form": form})
```

#### Template

Django **templates** are HTML files with additional markup to signify places where data can be dynamically inserted. The data used by the views file is called the **template context**.

Templates must be placed within the **/templates** folder within the app, and it is considered best practice to place templates within a nested subdirectory within it, e.g. **/templates/app**.

Django **template tags** are specified beween `{% .. %}` and allow for interpolation of data.

```py
<ul>
  {% for m in meetings %}

  {% endfor %}
</ul>
```

URLs can be built by using the `url` template tag, specifying the name of a URL
```py
urlpatterns = [
  path('', home, name='home')
]
```
```py
<a href="{% url 'home' %}">Home</a>
```

#### Models

In Django, a [**Model**](ttps://docs.djangoproject.com/en/3.1/topics/db/models/) class is mapped to a database table. Each object is a record in that table.

Model objects expose several attributes and methods

Get all objects
```py
meetings = Meeting.objects.all()
```
Get count of objects in database
```py
count = Meeting.objects.count()
```
Query for a specific object
```py
meeting = Meeting.objects.get(pk=id)
```
:point_right: [`get_object_or_404`](https://docs.djangoproject.com/en/3.1/topics/http/shortcuts/#get-object-or-404) may be better for most cases
```py
meeting = get_object_or_404(Meeting, pk=id)
```

Adding a new **app**
```sh
python manage.py startapp app
```
Then add to **settings.py** in project directory
```py
INSTALLED_APPS = [
  # ...
  'app',
]
```

There appears to be much flexibility in the arrangement of input controls in a form.

So long as the Submit button is child to the `form` element, tasks are accepted in the To-Do app.

Per Bulma documentation, the `field` class is intended as a container for `label.label`s, `.control`s, and optional `p.help` text. [:point_right:](https://bulma.io/documentation/form/general/#form-field)

In contrast, `control` is a **block** container meant to enhance single form controls and can only contain `input`, `select`, `button`, or `icon` elements. [:point_right:](https://bulma.io/documentation/form/general/#form-control)
```pug
form.field(method="POST", action="/")
  label.label Enter something to do
  .control
    | {{form.title}}
    | {% csrf_token %}
  button.button.is-primary(type="submit") Submit
```
