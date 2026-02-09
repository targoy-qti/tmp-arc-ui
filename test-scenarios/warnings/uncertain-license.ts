/*
 * Copyright (c) 2024 Third Party Vendor
 * 
 * Permission is hereby granted to any person obtaining a copy of this software
 * to use, copy, modify, and distribute the software for internal purposes only,
 * subject to the following conditions and restrictions:
 * 
 * 1. The software may not be used for commercial purposes without prior written consent.
 * 2. Redistributions must retain this copyright notice and permission notice.
 * 3. The software is provided "as is" without warranty of any kind.
 */

interface User {
    id: number;
    name: string;
    email: string;
}

class UserManager {
    private users: User[] = [];

    addUser(user: User): void {
        this.users.push(user);
    }

    getUser(id: number): User | undefined {
        return this.users.find(u => u.id === id);
    }

    getAllUsers(): User[] {
        return [...this.users];
    }
}

export { User, UserManager };
