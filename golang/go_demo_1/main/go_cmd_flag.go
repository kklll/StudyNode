package main

import (
	"flag"
	"fmt"
)

func main() {
	wordPtr := flag.String("help", "nil", "using it for help!")
	fmt.Println(*wordPtr)
	numbPtr := flag.Int("numb", 42, "an int")
	boolPtr := flag.Bool("fork", false, "a bool")
	var svar string
	flag.StringVar(&svar, "svar", "bar", " a string var")
	flag.Parse()
	fmt.Println("help:", *wordPtr)
	fmt.Println("numb:", *numbPtr)
	fmt.Println("fork:", *boolPtr)
	fmt.Println("svar:", svar)
	fmt.Println("tail:", flag.Args())
}
