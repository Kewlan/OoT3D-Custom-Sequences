#pragma once

#include <iostream>
#include <string>

bool StrIsInt(std::string s);

class Note {
  public:
    Note(std::istream& input);
    Note(int note);
    Note(std::string note);
    ~Note();

    Note operator+(const Note& note) const {
        return Note(m_note + note.m_note);
    }

    Note operator-(const Note& note) const {
        return Note(m_note - note.m_note);
    }

    Note operator+(const int& note) const {
        return Note(m_note + note);
    }

    Note operator-(const int& note) const {
        return Note(m_note - note);
    }

    bool operator>=(const Note& note) const {
        return m_note >= note.m_note;
    }

    bool operator<=(const Note& note) const {
        return m_note <= note.m_note;
    }

    explicit operator int() const {
        return m_note;
    }

    static int IntFromStr(std::string note);
    static std::string StrFromInt(int note);

    int Int();
    std::string Str();

    bool IsInvalid();

  private:
    int m_note;
    std::string m_cachedStr;
};

std::string operator+(const std::string& str, Note& note);
