# NUXT.js

Library building upon Vue which allows creation of universal Vue apps with _server-side rendering_, which allows _index.html_ to be generated and allows single-page apps to be available to search engines. Simplifies development of Vue apps with very little overhead.

Nuxt is not a replacement for _Express_, but it can work with _Express_.

## Installation and initialization

- `npx create-nuxt-app APPNAME` (npx is available by default as part of `npm`)
- Single-page app is not compatible with SEO because it does not produce text in HTML that is readable by search engines

## Folder structrure

Different from Vue structure

3 folders associated with forming the `template` portion, each of which contains a .vue file:
1. _components_
2. _layouts_
3. _pages_, which are placed into the nuxt element which exists in the _layouts/default.vue_ file

Vue files in the _pages/_ directory are rendered as prerendered HTML on corresponding URL endpoints on the client. (routing)

Underscore in the name of a folder, e.g. _\_id_ signals to Nuxt that the rest of the name will be a variable.

## Procedure
1. Create folder _nuxty/layouts/partials_ and file _nav.vue_
2. `scaffold` snippet to create structure of an empty Vue file
3. 

## Vue snippets
- `scaffold`: inserts basic template-script-style structure of a Vue file

## Vue elements
- `nuxt-link` instead of `a`
  `to` attribute instead of `href`

## Glossary
- routing


## Procedure
Make _recipes/_ folder in _pages/_, add _index.vue_.
Add `template` section

    section.recipes
     article
      div
       h1 Title
        p Some nice preview text

Add style section

    .recipes {
      display: flex;
      flex-flow: row wrap;
      justify-content: center;
      align-items: center;
    }
    .recipe {
      box-sizing: border-box;
      width: 280px;
      padding: 8px;
      border: 1px solid #ccc;
      box-shadow: 0 2px 2px #aaa;
    }

Copy `article` and contents for a second recipe

Add "thumbnail" class to `div`, along with inline styling for a background-image.

Start a new file in the _components/_ folder named _Recipe.vue_
`template`
    article.recipe
      .thumbnail(style="background-image: url('...')")
      h1 {{title}}
      p {{ previewText}}

`script`
    export default {
      props: ['thumbnail', 'title', 'previewText']
    }

convert inline styling to something dynamic:
`template`

    <div class="thumbnail" :style="{backgroundImage: 'url(' + thumbnail + ')'}" </div>

We now have a reusable component which we can register in _recipes/index.vue_
`script`

    import Recipe from '@/components/Recipe'

    export defulat {
      components: {
        Recipe
      }
    }

Change `article` tags to `Recipe`

Move `style` from `index.vue` to `Recipe.vue`