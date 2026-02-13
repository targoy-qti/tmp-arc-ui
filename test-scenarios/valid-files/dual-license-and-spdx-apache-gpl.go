// Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
// SPDX-License-Identifier: Apache-2.0 AND GPL-2.0



package main

import (
	"fmt"
	"strings"
	"time"
)

// Event represents a system event
type Event struct {
	ID        int
	Name      string
	Timestamp time.Time
	Data      map[string]interface{}
}

// EventLogger manages system events
// Licensed under Apache-2.0 AND GPL-2.0 (SPDX format)
type EventLogger struct {
	events []Event
	nextID int
}

// NewEventLogger creates a new EventLogger instance
func NewEventLogger() *EventLogger {
	return &EventLogger{
		events: make([]Event, 0),
		nextID: 1,
	}
}

// LogEvent adds a new event to the logger
func (el *EventLogger) LogEvent(name string, data map[string]interface{}) *Event {
	event := Event{
		ID:        el.nextID,
		Name:      name,
		Timestamp: time.Now(),
		Data:      data,
	}
	el.events = append(el.events, event)
	el.nextID++
	return &event
}

// GetEvent retrieves an event by ID
func (el *EventLogger) GetEvent(id int) *Event {
	for i := range el.events {
		if el.events[i].ID == id {
			return &el.events[i]
		}
	}
	return nil
}

// GetEventsByName retrieves all events with a specific name
func (el *EventLogger) GetEventsByName(name string) []Event {
	result := make([]Event, 0)
	for _, event := range el.events {
		if event.Name == name {
			result = append(result, event)
		}
	}
	return result
}

// GetEventCount returns the total number of logged events
func (el *EventLogger) GetEventCount() int {
	return len(el.events)
}

// ClearEvents removes all events from the logger
func (el *EventLogger) ClearEvents() {
	el.events = make([]Event, 0)
	el.nextID = 1
}

// PrintSummary prints a summary of all logged events
func (el *EventLogger) PrintSummary() {
	fmt.Printf("Total Events: %d\n", len(el.events))
	fmt.Println(strings.Repeat("-", 50))
	for _, event := range el.events {
		fmt.Printf("ID: %d | Name: %s | Time: %s\n",
			event.ID,
			event.Name,
			event.Timestamp.Format("2006-01-02 15:04:05"))
	}
}

func main() {
	logger := NewEventLogger()

	// Log some events
	logger.LogEvent("UserLogin", map[string]interface{}{
		"username": "alice",
		"ip":       "192.168.1.100",
	})

	logger.LogEvent("FileAccess", map[string]interface{}{
		"filename": "document.pdf",
		"action":   "read",
	})

	logger.LogEvent("UserLogin", map[string]interface{}{
		"username": "bob",
		"ip":       "192.168.1.101",
	})

	// Print summary
	logger.PrintSummary()

	// Get specific events
	loginEvents := logger.GetEventsByName("UserLogin")
	fmt.Printf("\nTotal login events: %d\n", len(loginEvents))
}
