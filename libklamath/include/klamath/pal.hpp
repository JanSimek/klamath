#pragma once

#include <cstdint>
#include <array>
#include <cstdint>
#include <iosfwd>

namespace klmth {
  namespace pal {
    const unsigned num_palette_colors = 256;
    const unsigned num_conversion_values = 32768;
    
    struct Rgb {
      uint8_t r;
      uint8_t g;
      uint8_t b;
    };

    struct File {
      std::array<Rgb, num_palette_colors> palette;
      std::array<uint8_t, num_conversion_values> rgb_conversion_table;
    };

    File parse(std::istream& in);
  }
}
