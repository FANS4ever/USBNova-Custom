#!/usr/bin/env python3
"""
Post-build script for USB Nova
Converts .bin to .uf2 for SAMD21 MKI boards (RP2040 boards auto-generate UF2)
"""

Import("env")
import subprocess
import os

def post_build_uf2(source, target, env):
    """Convert firmware.bin to firmware.uf2 for SAMD21 MKI boards using uf2conv"""
    
    env_name = env["PIOENV"]
    
    # Only MKI (SAMD21) needs manual UF2 conversion
    if "mki" not in env_name and "samd21" not in env_name:
        return
    
    bin_file = str(target[0])
    uf2_file = bin_file.replace(".bin", ".uf2")
    
    try:
        # Use uf2conv command-line tool (installed via cargo)
        result = subprocess.run(
            ["uf2conv", bin_file, "-o", uf2_file],
            capture_output=True,
            text=True,
            check=True
        )
        
        if os.path.exists(uf2_file):
            size = os.path.getsize(uf2_file)
            print(f"Created {uf2_file} ({size} bytes)")
        else:
            print(f"Warning: {uf2_file} was not created")
            
    except FileNotFoundError:
        print("\n" + "=" * 70)
        print("ERROR: uf2conv not found!")
        print("To install uf2conv, install rust, then `cargo install uf2conv`")
        print("=" * 70 + "\n")
    except subprocess.CalledProcessError as e:
        print(f"Error converting to UF2: {e}")
        if e.stderr:
            print(f"stderr: {e.stderr}")

# Register the post-build action
env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", post_build_uf2)
