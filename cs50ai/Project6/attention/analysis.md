# Analysis

## Layer 2, Head 7

When experimenting with various sentences, I noticed that Layer 2, Head 7 often shows strong attention between **determiners (like "a", "the") and the nouns they modify**.  
In the attention diagrams, the token for the determiner tends to have a bright cell aligned with the token for its following noun, suggesting that this head is attending from a determiner to the associated noun.

Example Sentences:
**Example sentences:**
- Input: `I saw a [MASK] in the garden.`  
  (The word **a** strongly attends to **[MASK]** which is expected to be a noun.)
- Input: `She found the [MASK] on the table.`  
  (The word **the** strongly attends to **[MASK]**, again a noun.)

## Layer 8, Head 3

Layer 8, Head 3 seems to pay attention to **pronouns and the verbs they relate to**, often focusing on the subject–predicate relationship.  
In several test sentences, I observed that a subject pronoun has a bright cell pointing toward the main verb of the sentence.


Example Sentences:
- Input: `He [MASK] the door carefully.`  
  (The token **he** attends strongly to the verb position `[MASK]`, indicating it is focusing on the action performed by the subject.)
- Input: `They [MASK] to the park yesterday.`  
  (The token **they** attends strongly to the verb position `[MASK]`, again showing a subject–verb link.)




