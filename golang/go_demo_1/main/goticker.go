package main

import (
	"fmt"
	"time"
)

//go的打点器
func main() {
	ticker := time.NewTicker(100 * time.Millisecond)
	done := make(chan bool)
	go func() {
		for {
			select {
			case <-done:
				return
			case t := <-ticker.C:
				fmt.Println("Tick at", t)
			}
		}
	}()
	time.Sleep(1000 * time.Millisecond)
	ticker.Stop()
	done <- true
	fmt.Println("tick stopped")
}
