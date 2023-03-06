#include "converter.hpp"

#include <unordered_map>
#include <vector>

struct NoteDifferer {
    Note n64_start;
    Note n3D_start;
    int length;
};

static std::vector<std::pair<std::vector<int>, std::vector<NoteDifferer>>> drumConversions;

void BanksInit() {
    drumConversions = {
        { {
              // Orchestra
              7,
          },
          {
              // 3D doesn't have the notes higher than fn6 on 64
              { Note("cn4"), Note("ds5"), 29 },

              // Same instrument as previous, but for some reason on 3D is placed alone on an2
              { Note("as3"), Note("an2"), 1 },

              // 64 has some more lower notes here, while 3DS has some higher.
              { Note("an2"), Note("gs2"), 8 },

              // Only one note has same pitch here. On 64 the rest go higher, while on 3D the rest go lower.
              { Note("cs2"), Note("en1"), 1 },

              // On 64 the rest go deeper, but on 3D they mirror the other notes.
              { Note("cs1"), Note("ds1"), 8 },

          } },
        { {
              // Staff
              37,
              // Staff 2
              38,
          },
          {
              // One extra high note here on 3D than Orche.
              { Note("cn4"), Note("ds5"), 30 },

              // Same as Orchestra.
              { Note("an2"), Note("gs2"), 8 },

              // Same as Orchestra.
              { Note("cs2"), Note("en1"), 1 },

              // Same as Orchestra.
              { Note("cs1"), Note("ds1"), 8 },

          } },
    };
}

bool IsBankValid(int bankIndex) {
    for (auto conversionSet : drumConversions) {
        for (auto bankNum : conversionSet.first) {
            if (bankIndex == bankNum) {
                return true;
            }
        }
    }
    return false;
}

Note GetConverted(int n3D_bankIndex, Note n64_note) {
    const auto& getNoteDiffererVector = [&]() {
        for (auto conversionSet : drumConversions) {
            for (auto bankNum : conversionSet.first) {
                if (n3D_bankIndex == bankNum) {
                    return conversionSet.second;
                }
            }
        }
    };

    std::vector<NoteDifferer> noteDiffererVector = getNoteDiffererVector();

    for (auto noteDifferer : noteDiffererVector) {
        Note n64_firstNote = noteDifferer.n64_start;
        Note n64_lastNote  = noteDifferer.n64_start + noteDifferer.length;

        if (n64_note >= n64_firstNote && n64_note <= n64_lastNote) {
            int diff = (int)(n64_note - n64_firstNote);
            return Note(noteDifferer.n3D_start - diff);
        }
    }

    return Note(-1);
}
