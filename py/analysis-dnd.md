[race_short]: #race_fn "List of strings corresponding to races"

# Analysis of [`dnd-tools`](https://github.com/savagezen/dnd-tools)
- Character creation seems like a place where OO techniques would be best suited
- The interactive portions would be great to adapt to `npyscreen`
- `enum` would be great for the strictly defined sets of characteristics, like race and class
- Output of tabulet data - `tabulate`

`expand` accepts dictionary objects that use range objects as keys and return an "expanded" dictionary object that includes every individual value within that range.

`start_fn` is the main entry point of the utility and depends on user to input an option that corresponds to one of 8 options
- Character creation, which calls the following functions in order:
  - [`race_fn`](#race_fn)
  - [`class_fn`](#class_fn)
  - `height_fn`
  - `weight_fn`
  - `age_fn`
  - `gender_fn`
  - `abilities_fn`
  - `race_bonus_fn`
  - `saves_fn`
  - `hp_fn`
  - `alignment_fn`
  - `summary_fn`
  - `name_fn`
  - `save_fn`

#### race_fn
`race_fn` declares the `char_race` variable as a global, and it is defined by user input. 
- If the value corresponds **exactly** to one provided in [`race_short`], it is left unchanged.
- If the input indicates random choice, a random element is selected using `random.choice` and assigned to `char_race`
- Otherwise, the function calls itself again!

#### class_fn
`class_fn` presents contents of `class_npc` or `char_class`, based on whether or not User is defining an NPC or the character

