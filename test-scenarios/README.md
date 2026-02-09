# Test Scenarios for Copyright-License-Checker

This directory contains test files that demonstrate various scenarios for the copyright-license-checker-action.

## Directory Structure

```
test-scenarios/
├── valid-files/           # Files that should PASS the checker
├── blocking-errors/       # Files that should FAIL and block the build
├── warnings/              # Files that generate warnings but don't block
├── excluded-files/        # Files that are excluded from checks
└── README.md             # This file
```

## Test Scenarios

### ✅ Valid Files (Should PASS)

1. **proper-license.py**
   - Proper BSD-3-Clause license with Qualcomm copyright
   - Standard format that should pass all checks
   - **Expected Result**: ✅ PASS

2. **multiple-copyrights.cpp**
   - Multiple copyright holders (original author + Qualcomm)
   - Demonstrates proper handling of multiple copyrights
   - **Expected Result**: ✅ PASS

3. **mit-license.go**
   - MIT license (compatible permissive license)
   - Shows that other permissive licenses are allowed
   - **Expected Result**: ✅ PASS

4. **apache-license.rb**
   - Apache-2.0 license (compatible permissive license)
   - Another example of allowed permissive license
   - **Expected Result**: ✅ PASS

### 🚨 Blocking Errors (Should FAIL)

1. **missing-license.js**
   - New source file without any license header
   - **Expected Error**: "No license added for source file"
   - **Compliance Impact**: MEDIUM

2. **incompatible-license.java**
   - Uses GPL-3.0 (copyleft license incompatible with BSD)
   - **Expected Error**: "Incompatible license added: GPL-3.0-only"
   - **Compliance Impact**: HIGH

3. **copyright-deletion.c**
   - Contains copyright that should not be removed
   - If "Copyright (c) 2023 Original Developer" is deleted, it will fail
   - **Expected Error**: "Copyright deletions detected"
   - **Compliance Impact**: HIGH

4. **license-change.h**
   - If license is changed from BSD-3-Clause to another license
   - **Expected Error**: "License deleted: BSD-3-Clause and license added: [NEW_LICENSE]"
   - **Compliance Impact**: CRITICAL

### ⚠️ Warnings (Non-blocking)

1. **uncertain-license.ts**
   - Custom license with non-standard terms and restrictions
   - **Expected Warning**: "Incompatible license added: LicenseRef-scancode-unknown"
   - **Build Status**: Continues with warning
   - **Action Required**: Manual review recommended

2. **freeware-license.swift**
   - Freeware license with usage restrictions
   - **Expected Warning**: "Incompatible license added: LicenseRef-scancode-unknown"
   - **Build Status**: Continues with warning
   - **Action Required**: Manual review recommended

3. **shareware-license.kt**
   - Shareware license with trial period and registration requirements
   - **Expected Warning**: "Incompatible license added: LicenseRef-scancode-unknown"
   - **Build Status**: Continues with warning
   - **Action Required**: Manual review recommended

4. **proprietary-license.sh**
   - Proprietary and confidential license with strict restrictions
   - **Expected Warning**: "Incompatible license added: LicenseRef-scancode-unknown"
   - **Build Status**: Continues with warning
   - **Action Required**: Manual review recommended

### 📄 Excluded Files

1. **documentation.md**
   - Markdown file without license header
   - **Expected Result**: Ignored (`.md` files are automatically excluded)
   - **Build Status**: No checks performed

## How to Use These Test Files

### Testing with the Action

1. **Create a test branch**:
   ```bash
   git checkout -b test-license-checker
   ```

2. **Add test files to your PR**:
   ```bash
   git add test-scenarios/
   git commit -m "test: add license checker test scenarios"
   git push origin test-license-checker
   ```

3. **Create a Pull Request** and observe the copyright-license-checker-action results

### Expected Behavior

- **Valid files**: Should pass without any errors or warnings
- **Blocking errors**: Should fail the build with specific error messages
- **Warnings**: Should show warnings but allow the build to continue
- **Excluded files**: Should be ignored completely

## Testing Specific Scenarios

### Test Missing License
```bash
# Add the file without license
git add test-scenarios/blocking-errors/missing-license.js
git commit -m "test: missing license scenario"
```

### Test Copyright Deletion
```bash
# Modify copyright-deletion.c to remove the original copyright
# Then commit and observe the error
```

### Test License Change
```bash
# Change BSD-3-Clause to MIT in license-change.h
# Then commit and observe the error
```

### Test Incompatible License
```bash
# Add the GPL-licensed file
git add test-scenarios/blocking-errors/incompatible-license.java
git commit -m "test: incompatible license scenario"
```

## Compliance Categories

### Permissive Licenses (Generally Allowed)
- BSD-3-Clause
- BSD-3-Clause-Clear
- MIT
- Apache-2.0
- ISC
- CC0-1.0
- Zlib

### Copyleft Licenses (Restricted)
- GPL-2.0
- GPL-3.0
- AGPL-3.0
- LGPL-3.0

### Excluded File Types
- `.md` (Markdown)
- `.patch` (Patch files)
- `.bb` (BitBake recipes)

## Additional Resources

- [Copyright-License-Checker Action](https://github.com/qualcomm/copyright-license-checker-action)
- [COMPLIANCE.md](/local/mnt/workspace/copyright-license-checker-action/COMPLIANCE.md) - Detailed compliance documentation
- [Action README](/local/mnt/workspace/copyright-license-checker-action/README.md) - Usage instructions

## Notes

- These test files are for demonstration and testing purposes only
- Always ensure your actual source code has proper license headers
- Consult with your legal team for complex licensing questions
- Use `.licenseignore` to exclude vendored dependencies or generated files
