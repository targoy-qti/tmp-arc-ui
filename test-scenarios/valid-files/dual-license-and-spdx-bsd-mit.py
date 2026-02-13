#!/usr/bin/env python3
# Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
# SPDX-License-Identifier: BSD-3-Clause AND MIT

from typing import List, Optional
from dataclasses import dataclass


@dataclass
class User:
    """Represents a user in the system."""
    id: int
    username: str
    email: str
    active: bool = True


class UserManager:
    """
    A simple user management system demonstrating dual-license with AND operator.
    Licensed under BSD-3-Clause AND MIT (SPDX format).
    """

    def __init__(self):
        self.users: List[User] = []
        self.next_id: int = 1

    def add_user(self, username: str, email: str) -> User:
        """Add a new user to the system."""
        user = User(id=self.next_id, username=username, email=email)
        self.users.append(user)
        self.next_id += 1
        return user

    def get_user(self, user_id: int) -> Optional[User]:
        """Get a user by ID."""
        for user in self.users:
            if user.id == user_id:
                return user
        return None

    def get_user_by_username(self, username: str) -> Optional[User]:
        """Get a user by username."""
        for user in self.users:
            if user.username == username:
                return user
        return None

    def deactivate_user(self, user_id: int) -> bool:
        """Deactivate a user."""
        user = self.get_user(user_id)
        if user:
            user.active = False
            return True
        return False

    def get_active_users(self) -> List[User]:
        """Get all active users."""
        return [user for user in self.users if user.active]

    def get_user_count(self) -> int:
        """Get total number of users."""
        return len(self.users)


def main():
    """Main function demonstrating UserManager usage."""
    manager = UserManager()

    # Add some users
    user1 = manager.add_user("alice", "alice@example.com")
    user2 = manager.add_user("bob", "bob@example.com")
    user3 = manager.add_user("charlie", "charlie@example.com")

    print(f"Total users: {manager.get_user_count()}")
    print(f"Active users: {len(manager.get_active_users())}")

    # Deactivate a user
    manager.deactivate_user(user2.id)
    print(f"Active users after deactivation: {len(manager.get_active_users())}")

    # Find user by username
    found_user = manager.get_user_by_username("alice")
    if found_user:
        print(f"Found user: {found_user.username} ({found_user.email})")


if __name__ == "__main__":
    main()
