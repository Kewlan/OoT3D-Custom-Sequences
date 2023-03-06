#include <vector>
#include <algorithm>

#include "note.hpp"
#include "helpers.hpp"

static const std::vector<std::string> ctrNotes = {
    "cn", "cs", //
    "dn", "ds", //
    "en",       //
    "fn", "fs", //
    "gn", "gs", //
    "an", "as", //
    "bn",       //
};

inline void NoteBoundsCheck(int& note) {
    if (note < 0 || note > 127) {
        note = -1; // Invalid
    }
}

Note::Note(std::istream& input) {
    std::string note;
    input >> note;

    if (StrIsInt(note)) {
        m_note = std::stoi(note);
        NoteBoundsCheck(m_note);
        return;
    }

    m_note = IntFromStr(note);
    NoteBoundsCheck(m_note);
}

Note::Note(int note) {
    m_note = note;
    NoteBoundsCheck(m_note);
}

Note::Note(std::string note) {
    m_note = IntFromStr(note);
    NoteBoundsCheck(m_note);
}

Note::~Note() = default;

int Note::IntFromStr(std::string noteStr) {
    // Remove spaces
    for (size_t pos = 0; pos < noteStr.size(); pos++) {
        if (isspace(noteStr.at(pos))) {
            noteStr.erase(pos, 1);
            pos--;
        }
    }

    if (noteStr.size() < 3 || noteStr.size() > 4) {
        return -1;
    }

    // Note
    int noteInt = -1;

    std::string note = noteStr.substr(0, 2);
    for (size_t i = 0; i < ctrNotes.size(); i++) {
        if (note.compare(ctrNotes[i]) == 0) {
            noteInt = (int)i;
            break;
        }
    }

    if (noteInt == -1) {
        return -1;
    }

    // Octave
    int octaveInt = -1;

    std::string octave;
    if (noteStr.size() == 4) {
        octave = noteStr.substr(2, 4);
        std::replace(octave.begin(), octave.end(), 'm', '-');
    } else {
        octave = noteStr.at(2);
    }

    if (!StrIsInt(octave)) {
        return -1;
    }

    octaveInt = std::stoi(octave);

    return (octaveInt + 1) * 12 + noteInt;
}

std::string Note::StrFromInt(int noteInt) {
    if (noteInt < 0 || noteInt > 127) {
        return "Invalid";
    }
    std::string out;

    out += ctrNotes.at(noteInt % 12);          // Note
    out += std::to_string((noteInt / 12) - 1); // Octave
    std::replace(out.begin(), out.end(), '-', 'm');

    return out;
}

int Note::Int() {
    return m_note;
}

std::string Note::Str() {
    if (m_note == -1) {
        return "Invalid";
    }

    if (!m_cachedStr.empty()) {
        return m_cachedStr;
    }

    m_cachedStr = StrFromInt(m_note);

    return m_cachedStr;
}

bool Note::IsInvalid() {
    return m_note == -1;
}

std::string operator+(const std::string& str, Note& note) {
    return str + note.Str();
}
