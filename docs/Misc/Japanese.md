# Japanese

NO and KOTO are both used to [nominalize](https://www.japanesepod101.com/lesson/intermediate-questions-answered-by-hiroko-5-difference-between-koto-and-no/) clauses and verbs in different contexts.


``` title="no"
友達が話しているのが聞こえました。# (1)
```

1. "I heard my friends talking."

``` title="koto"
今年の目標は、試験に合格することです。 # (1)
```

1. "My goal this year is to pass the exam."

#### IME
:   
    Typing in Japanese is done by applications known as **IME** (input method editor).
    The **preedit** or [**composition string**](https://udn.realityripple.com/docs/Mozilla/IME_handling_guide) refers to the string composed by the user using an IME, which can then be **converted** or rendered in the desired script.

    For example, a user may input the string "watasinonamaehanakanodesu", which is rendered as the following preedit:
    ```
    わたしのなまえはなかのです
    ```

    By pressing the **convert** key ++tab++, the IME then opens a menu that allows the preedit to be converted to a mixture of hiragana and kanji:
    ```
    私の名前は中野です
    ```

    Some conventions date from ancient practice and are silently assumed now.

    For example, the convention that ++f6++ produces hiragana and ++f7++ katakana is associated with [ATOK](https://en.wikipedia.org/wiki/ATOK), a Japanese IME with roots in the 1980s.

    Microsoft's IME is built-in to Windows, but on Linux there are multiple IMEs available.
    **Mozc** appears to be the most popular, but [fcitx5](https://wiki.archlinux.org/title/Fcitx5) is installed by default on Garuda and offers Mozc-like functionality.


#### Furigana
:   
    In HTML, furigana can be placed with the **ruby** and **rt** HTML tags, which are supported by Anki:

    In order to render: <ruby>目標<rt>もくひょう</rt></ruby> (objective)
    ```html
    <ruby>目標<rt>もくひょう</rt></ruby> 
    ```
