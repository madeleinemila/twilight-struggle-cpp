## Twilight Struggle

🎲 A CLI tool for the boardgame Twilight Struggle written in C++.

### Features

#### Rolls and realignment calculations

- `./roll` --> Rolls one die.

- `./roll --realign` --> Rolls a die each for USSR & US and provides the difference.

- `./roll --realign [ us(a)=# | ussr=# ]` -> Rolls a die each for USSR & US and provides the difference, factoring in board advantage.

#### Example output

```
$ ./roll --realign us=1

USSR advantage: 0
🎲 USSR rolled: 2
US advantage: 1
🎲 US rolled: 5
🔵 US gets to remove 4 USSR influence.
```

### To build

`make dev`
or
`make release`
