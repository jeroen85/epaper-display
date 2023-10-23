int GetTextBounds(esphome::display::Display* it, esphome::font::Font *font, const char *buffer)
{
    int x1 = 0;     // A pointer to store the returned x coordinate of the upper left corner in. 
    int y1 = 0;     // A pointer to store the returned y coordinate of the upper left corner in.
    int width = 0;  // A pointer to store the returned text width in.
    int height = 0; // A pointer to store the returned text height in. 
    it->get_text_bounds(0, 0, buffer, font, TextAlign::TOP_LEFT, &x1, &y1, &width, &height);
    return width;
}

int GetTextWidth(esphome::display::Display* it, esphome::font::Font *font, const char* formatting, const char *raw_text){
    char temp_buffer[80];
    sprintf(temp_buffer, formatting, raw_text);
    return GetTextBounds(it, font, temp_buffer);
}

int GetTextWidth(esphome::display::Display* it, esphome::font::Font *font, const char* formatting){
    char temp_buffer[80];
    sprintf(temp_buffer, formatting);
    return GetTextBounds(it, font, temp_buffer);
}

int GetTextWidth(esphome::display::Display* it, esphome::font::Font *font, const char* formatting, float& raw_text){
    char temp_buffer[80];
    sprintf(temp_buffer, formatting, raw_text);
    return GetTextBounds(it, font, temp_buffer);
}

int GetTextWidth(esphome::display::Display* it, esphome::font::Font *font, const char* formatting, float& raw_text1, float& raw_text2){
    char temp_buffer[80];
    sprintf(temp_buffer, formatting, raw_text1, raw_text2);
    return GetTextBounds(it, font, temp_buffer);
}

// Calculate the width of time format
int GetTextWidth(esphome::display::Display* it, esphome::font::Font *font, const char* formatting, esphome::ESPTime time){
    auto c_tm = time.to_c_tm();
    size_t buffer_length = 80;
    char temp_buffer[buffer_length];
    strftime(temp_buffer, buffer_length, formatting, &c_tm);
    return GetTextBounds(it, font, temp_buffer);
}
