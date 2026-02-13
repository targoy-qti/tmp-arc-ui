/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * 
 * This file is licensed under both the BSD-3-Clause License AND GPL-2.0 License.
 * You must comply with BOTH licenses to use this code.
 * 
 * BSD-3-Clause License:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * GPL-2.0 License:
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * A simple string processor demonstrating dual-license with AND operator.
 * This code must comply with BOTH BSD-3-Clause AND GPL-2.0 licenses.
 */
class StringProcessor {
private:
    std::vector<std::string> strings;

public:
    StringProcessor() = default;

    void addString(const std::string& str) {
        if (!str.empty()) {
            strings.push_back(str);
        }
    }

    void removeString(const std::string& str) {
        strings.erase(
            std::remove(strings.begin(), strings.end(), str),
            strings.end()
        );
    }

    std::vector<std::string> getAllStrings() const {
        return strings;
    }

    size_t getCount() const {
        return strings.size();
    }

    void sortStrings() {
        std::sort(strings.begin(), strings.end());
    }

    void clear() {
        strings.clear();
    }

    std::string concatenate(const std::string& delimiter = " ") const {
        if (strings.empty()) {
            return "";
        }

        std::string result = strings[0];
        for (size_t i = 1; i < strings.size(); ++i) {
            result += delimiter + strings[i];
        }
        return result;
    }
};

int main() {
    StringProcessor processor;
    
    processor.addString("Hello");
    processor.addString("World");
    processor.addString("Qualcomm");
    
    std::cout << "String count: " << processor.getCount() << std::endl;
    std::cout << "Concatenated: " << processor.concatenate() << std::endl;
    
    processor.sortStrings();
    std::cout << "After sorting: " << processor.concatenate() << std::endl;
    
    return 0;
}
