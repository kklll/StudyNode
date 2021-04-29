package main

import (
	"fmt"
	"time"
)

func main() {
	done := make(chan bool)
	go worker(done)
	<-done
}
func worker(done chan bool) {
	fmt.Printf("working----")
	time.Sleep(time.Second)
	fmt.Println("done")
	done <- true
}
