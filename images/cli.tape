# https://github.com/charmbracelet/vhs

# Setup
Set Shell zsh # issue with bash currently https://github.com/charmbracelet/vhs/issues/419
Set FontSize 20
Set Width 700
Set Height 700
Set Padding 10
Set Margin 10
Set MarginFill "#6B50FF"
Set WindowBar Colorful
Set BorderRadius 10
Hide
Type "cd ../build"
Enter
Type "clear"
Enter
Show

Type './cli'
Enter

Sleep 2s
Screenshot cli.png