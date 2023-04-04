# Anki cards

For language-learning purposes, it appears the best approach to use with Anki is to routinely watch media and extract audio clips of interest, for the purpose of producing a cloze note with a transcript.

1. Download audio and create a clip.
2. Drag and drop the clip into a new note.
3. Paste the [template HTML](#message-bubbles) to make use of the text message format, if desired.
4. Copy and paste the transcription appropriately.
5. Create cloze items.

## Audio

```html
[sound:clip.mp3]
```

Anki will autoplay these clips by default, though this behavior can be disabled in [deck options](https://docs.ankiweb.net/deck-options.html#audio).

## Message bubbles

This CSS was found [here](https://codepen.io/AllThingsSmitty/pen/jommGQ).

```html title="Basic pattern"
<div class="imessage">
    <p class="from-them">

    </p>
    <p class="from-me">
        <span class="translation"></span>
    </p>
</div>
```


```pug
.imessage
    p.from-them Oi, td bem?
    p.from-me {{c1::Td}} sim
// (1)
```

1. ![](oi.png)

```pug
.imessages
    p.from-them Me dijiste que si esperaba ser pagada y te dije que no
    p.from-me {{c1::Podría}} {{c2::haberte}} pagado por tus salarios perdidos 
        span.translation I could have paid your for your lost wages  
// (1)
```

1. ![](translation.png)