# Images generation

Same image width for the CLI and the GUI &rarr; same columns width in the rendering of the README.<br/>
For the CLI image, dimensions are enforced in [cli.tape](cli.tape). For the GUI image, dimensions are given as command line arguments.

**CLI**

```bash
vhs cli.tape
```

**GUI**

```bash
./gui gfx:geometry=700x700
```
Then adjust panels sizes, rotate the cube a bit, and take a screenshot
