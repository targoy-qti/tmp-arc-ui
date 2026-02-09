/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * 
 * This file is licensed under both the Apache License 2.0 AND the MIT License.
 * You must comply with BOTH licenses to use this code.
 * 
 * Apache License 2.0:
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * MIT License:
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

interface ValidationRule {
  name: string;
  validate: (value: any) => boolean;
  errorMessage: string;
}

class DataValidator {
  private rules: ValidationRule[] = [];

  addRule(rule: ValidationRule): void {
    this.rules.push(rule);
  }

  validate(data: any): { isValid: boolean; errors: string[] } {
    const errors: string[] = [];

    for (const rule of this.rules) {
      if (!rule.validate(data)) {
        errors.push(rule.errorMessage);
      }
    }

    return {
      isValid: errors.length === 0,
      errors,
    };
  }

  clearRules(): void {
    this.rules = [];
  }

  getRuleCount(): number {
    return this.rules.length;
  }
}

// Example usage
const validator = new DataValidator();

validator.addRule({
  name: 'notEmpty',
  validate: (value) => value !== null && value !== undefined && value !== '',
  errorMessage: 'Value cannot be empty',
});

validator.addRule({
  name: 'minLength',
  validate: (value) => typeof value === 'string' && value.length >= 3,
  errorMessage: 'Value must be at least 3 characters long',
});

const result1 = validator.validate('ab');
console.log('Validation result:', result1);

const result2 = validator.validate('valid');
console.log('Validation result:', result2);

export { DataValidator, ValidationRule };
