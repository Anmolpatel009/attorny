#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::transform
#include <sstream>   // for std::istringstream

struct Paragraph {
    std::string title;
    std::string content;
};

// Function to convert a string to lowercase
void toLowerCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
}

bool containsSubstring(const std::string& str, const std::string& substr) {
    std::string strLower(str);
    std::string substrLower(substr);

    // Convert both strings to lowercase for case-insensitive comparison
    std::transform(strLower.begin(), strLower.end(), strLower.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    std::transform(substrLower.begin(), substrLower.end(), substrLower.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    return (strLower.find(substrLower) != std::string::npos);
}

bool containsAllKeywords(const std::string& title, const std::vector<std::string>& keywords) {
    for (const auto& keyword : keywords) {
        if (!containsSubstring(title, keyword))
            return false;
    }
    return true;
}

int main() {
    // Sample paragraphs and titles
    Paragraph paragraphs[] = {
        {
        "Dowry Harassment",
        "Your case falls under dowry harassment, which is a serious offense punishable under the Indian Penal Code (IPC).\n\n"
        "SECTION 498A IPC\n"
        "Section 498A deals with cruelty to a married woman by her husband or his relatives. If any person, being the husband or the relative of the husband of a woman, subjects her to cruelty, he shall be punished with imprisonment for a term which may extend to three years and shall also be liable to fine.\n\n"
        "SECTION 304B IPC\n"
        "Section 304B deals with dowry death. If the death of a woman is caused by burns or bodily injury or occurs otherwise than under normal circumstances within seven years of her marriage and it is shown that soon before her death, she was subjected to cruelty or harassment by her husband or his relatives regarding dowry demand, it is considered dowry death.\n\n"
        "SECTION 113A IPC\n"
        "Section 113A establishes a presumption as to the abetment of suicide by a married woman. If a married woman commits suicide within seven years of her marriage and it is shown that her husband or his relatives subjected her to cruelty, the court may presume that such suicide was abetted by her husband or his relatives.\n\n"
        "SECTION 3 of Dowry Prohibition Act\n"
        "Section 3 of the Dowry Prohibition Act, 1961, prohibits the giving or taking of dowry. Any person who gives, takes or abets the giving or taking of dowry shall be punishable with imprisonment for a term which may extend to five years, and shall also be liable to a fine.\n\n"
        // Add more IPC sections...

    },
    {
        "Cyberbullying",
        "If you have been a victim of cyberbullying, there are specific provisions in the Indian Penal Code (IPC) that address these issues.\n\n"
        "SECTION 509 IPC\n"
        "Section 509 deals with word, gesture, or act intended to insult the modesty of a woman. If any person intends to insult the modesty of a woman by using words, gestures, or acts, he shall be punished with imprisonment for a term which may extend to one year or with a fine or both.\n\n"
        "SECTION 66E IT ACT\n"
        "Section 66E of the Information Technology Act (IT Act) deals with the violation of privacy by capturing, publishing, or transmitting images of a private area of any person without their consent. If convicted, the offender may be punished with imprisonment for a term which may extend to three years and a fine.\n\n"
        "SECTION 66A IT ACT\n"
        "Section 66A of the Information Technology Act (IT Act) dealt with punishment for sending offensive messages through communication services. However, this section has been struck down by the Supreme Court of India as unconstitutional.\n\n"
        "SECTION 66C IT ACT\n"
        "Section 66C of the Information Technology Act (IT Act) deals with identity theft. If a person fraudulently or dishonestly makes use of the electronic signature, password, or any other unique identification feature of any other person, he shall be punished with imprisonment for a term which may extend to three years and shall also be liable to a fine.\n\n"
        // Add more IPC sections...

    },
    {
        "Forgery and Fraud",
        "Your case involves forgery and fraud, which are offenses punishable under the Indian Penal Code (IPC).\n\n"
        "SECTION 420 IPC\n"
        "Section 420 deals with cheating and dishonestly inducing delivery of property. Whoever cheats and thereby dishonestly induces the person deceived to deliver any property to any person or to make, alter, or destroy the whole or any part of a valuable security, or anything which is signed or sealed, and which is capable of being converted into a valuable security, shall be punished with imprisonment of either description for a term which may extend to seven years, and shall also be liable to fine.\n\n"
        "SECTION 463 IPC\n"
        "Section 463 deals with forgery. Whoever makes any false documents or false electronic records with the intent to cause damage or injury to the public or to any person, or to support any claim or title, or to cause any person to part with property, or to enter into any express or implied contract, shall be punished with imprisonment for a term which may extend to two years or with a fine or both.\n\n"
        "SECTION 467 IPC\n"
        "Section 467 deals with forgery of valuable security, will, or authority to make or transfer any valuable security. If a person forges a valuable security, a will, or an authority to make or transfer any valuable security, intending that such forgery shall be used for the purpose of cheating, he shall be punished with imprisonment for life or with imprisonment of either description for a term which may extend to ten years, and shall also be liable to fine.\n\n"
        "SECTION 471 IPC\n"
        "Section 471 IPC deals with using as genuine a forged document. Whoever fraudulently or dishonestly uses as genuine any document which he knows or has reason to believe to be a forged document shall be punished with imprisonment of either description for a term which may extend to seven years, or with fine, or with both.\n\n"
        // Add more IPC sections...

    },
    {
        "Robbery and robbed",
        "Your case involves robbery, which is a serious offense punishable under the Indian Penal Code (IPC).\n\n"
        "SECTION 392 IPC\n"
        "Section 392 deals with punishment for robbery. If a person commits robbery, he shall be punished with rigorous imprisonment for a term which may extend to seven years, and shall also be liable to fine.\n\n"
        "SECTION 393 IPC\n"
        "Section 393 IPC deals with attempting to commit robbery. If a person attempts to commit robbery, he shall be punished with rigorous imprisonment for a term which may extend to seven years, and shall also be liable to fine.\n\n"
        "SECTION 394 IPC\n"
        "Section 394 IPC deals with voluntarily causing hurt in committing robbery. If a person, in committing robbery, voluntarily causes hurt to any person, he shall be punished with imprisonment for life, or with rigorous imprisonment for a term which may extend to ten years, and shall also be liable to fine.\n\n"
        // Add more IPC sections...

    },
    {
        "Assault and Robbery",
        "Your case involves assault and robbery, which are serious offenses punishable under the Indian Penal Code (IPC).\n\n"
        "SECTION 392 IPC\n"
        "Section 392 deals with punishment for robbery. If a person commits robbery, he shall be punished with rigorous imprisonment for a term which may extend to seven years, and shall also be liable to fine.\n\n"
        "SECTION 393 IPC\n"
        "Section 393 IPC deals with attempting to commit robbery. If a person attempts to commit robbery, he shall be punished with rigorous imprisonment for a term which may extend to seven years, and shall also be liable to fine.\n\n"
        "SECTION 394 IPC\n"
        "Section 394 IPC deals with voluntarily causing hurt in committing robbery. If a person, in committing robbery, voluntarily causes hurt to any person, he shall be punished with imprisonment for life, or with rigorous imprisonment for a term which may extend to ten years, and shall also be liable to fine.\n\n"
        // Add more IPC sections...

    },
    {
        "Hit and Run",
        "Your case involves a hit and run incident, which is a serious offense punishable under the Indian Penal Code (IPC) and the Motor Vehicles Act.\n\n"
        "SECTION 279 IPC\n"
        "Section 279 IPC addresses rash and negligent driving. If any person drives a vehicle in a rash and negligent way causing or likely to cause injury or endanger the life of any person, he shall be punished with imprisonment for a term which may extend to six months, or with fine which may extend to one thousand rupees, or with both.\n\n"
        "SECTION 304A IPC\n"
        "Section 304A IPC deals with causing death by negligence. If a person causes the death of another person by a rash or negligent act not amounting to culpable homicide, he shall be punished with imprisonment for a term which may extend to two years, or with fine, or with both.\n\n"
        "SECTION 134A of Motor Vehicles Act\n"
        "Section 134A of the Motor Vehicles Act deals with punishment for drunken driving. If a person is found driving under the influence of alcohol or drugs, he shall be punishable for the first offence with imprisonment for a term which may extend to six months, or with fine which may extend to two thousand rupees, or with both.\n\n"
        // Add more IPC sections...

    }

    
    };

    // Get user input
    std::string userInput;
    std::cout << "Enter keywords to search for (separated by spaces): "<<"\n";
    std::getline(std::cin, userInput);

    // Convert input to lowercase for case-insensitive comparison
    toLowerCase(userInput);

    // Split the input into words
    std::istringstream iss(userInput);
    std::vector<std::string> keywords;
    std::string word;
    while (iss >> word) {
        keywords.push_back(word);
    }

    // Check each paragraph for presence of all keywords (case-insensitive)
    for (const auto& paragraph : paragraphs) {
        if (containsAllKeywords(paragraph.title, keywords)) {
            std::cout << "Title: " << paragraph.title << "\n";
            std::cout << "Content: " << paragraph.content <<"\n\n"; 
        }
    }

    return 0;
}
