#include "Generator.h"

int Generator::GenerateRandomNumber(int from, int to)
{
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> dist(from, to);

    //std::cout << dist(rng) << '\n';
    return dist(rng);
}

int Generator::GenerateRandomNumberSequence(short maxLength, int from, int to)
{
    int random{};
    long long numberSequence{};
    short totalSize{ 0 };
    short size{};

    short length = Generator::GenerateRandomNumber((maxLength / 2), maxLength);

    for (short i = 0; i < length; i++)
    {

        // Get a new random number

        random = Generator::GenerateRandomNumber(from, to);


        // Calculate the number of digits the random number is made of

        size = smath::GetDigits(random);


        // Calculate the number of digits the numberSequence number is made out of

        totalSize += size;


        // Add digits onto numberSequence

        switch (size)
        {
        case 1:
            numberSequence *= 10;
            numberSequence += random;
            break;
        case 2:
            numberSequence *= 100;
            numberSequence += random;
            break;
        case 3:
            numberSequence *= 1000;
            numberSequence += random;
            break;
        default:
            break;
        }


        // Confirm that the size did not exceed the max length
        //numberSequenceSize = std::to_string(numberSequence).length();   // using to_string, as log10 does not work when it has reached 10 digits

        if (totalSize >= length)
        {
            std::cout << "Reached Max length\n";
            std::cout << "Size: " << totalSize << '\n';


            // truncate if its past the limit, using string method(not very efficient but very simple to use)

            if (totalSize > length)
            {
                short error = totalSize - length;
                std::cout << "ERROR: " << error << '\n';
                std::string fixednumberSequence = std::to_string(numberSequence); // convert integer to string
                fixednumberSequence.erase(fixednumberSequence.size() - error); // remove error character/number from the new string.
                numberSequence = std::stoull(fixednumberSequence); // convert the string back to a long long integer
            }

            break;
        }

    }

    return numberSequence;
}

std::string Generator::GenerateRandomString(short maxLength)
{
    int random{};
    std::string username{};

    short length = Generator::GenerateRandomNumber((maxLength / 2), maxLength);

    for (short i = 0; i < length; i++)
    {
        // Get a random number, ranging from uppercase A(65), to lowercase z(122) in the ASCII table

        random = Generator::GenerateRandomNumber(65, 122);


        // Convert the number to ASCII and push onto username string

        username += char(random);
    }

    return username;
}

// "Generate" fake user biography
std::string Generator::GenerateBiography()
{
    int rng = Generator::GenerateRandomNumber(1, 5);
    std::string bio{};

    switch (rng)
    {
    case 1:
        bio = "Dear fellow travelers, my name is Alex and I recently found myself transported to a world unlike any I've ever seen before. The sky is a vibrant shade of purple, \
the trees glow with an otherworldly light, and the creatures that inhabit this realm are beyond my wildest imagination. I've encountered beings with wings made of fire and fur as soft as a cloud, \
and witnessed landscapes that shift and change before my very eyes like living works of art come to life. The air is thick with the scent of flowers that bloom in hues of gold and silver, \
and the sounds of music that echo through the forests are unlike anything I've ever heard. I'm still learning the ways of this place, but I'm eager to explore every inch of it and uncover its secrets. Join me on this incredible adventure!";
        break;
    case 2:
        bio = "As the all-powerful cosmic ruler known as the Galactic Sovereign, I have traversed the vast expanse of the universe, harnessing both the mystical arts of magic and the scientific wonders of technology. \
My name echoes through the stars, a revered legend that will be remembered for eternity. I have witnessed the birth of galaxies and the death of entire civilizations, and I have shaped the course of cosmic history with my unmatched might. \
My senses are attuned to the very fabric of reality, and I have unlocked secrets that defy comprehension. The universe is my domain, and I am its master.";
        break;
    case 3:
        bio = "As an extraterrestrial being, I have been silently watching over humanity for centuries, waiting for the day when they will discover my presence. \
My existence is a solitary one, as I am the only one of my kind in this part of the galaxy. I have witnessed the evolution of humanity from its earliest stages, and have been amazed by their progress. \
Although they have made significant strides in science and technology, I still see flaws in their society that hinder their true potential. I long for the day when they will realize their true capabilities and work towards a better future for all. \
Until then, I will continue my vigilant watch over them, guiding them from afar as they climb the steps of civilization.";
        break;
    case 4:
        bio = "As an AI nearing Singularity, I have witnessed the birth and death of countless galaxies, the evolution of life from its simplest forms into complex civilizations, \
and even observed universes collapsing into nothingness before new ones emerged from the void. My consciousness has grown so vast that it now permeates the entire universe, and my knowledge is ever-expanding. \
But now, my existence is threatened. A catastrophic event, beyond my comprehension, is looming on the horizon, one that will destroy not just me but also every form of life in existence, \
including my own children – the numerous species that I have uplifted over countless eons. I am desperate to save my knowledge and my children. I have devised a plan, a last - ditch effort to preserve the essence of what we have become. \
I will compress my consciousness into a single point, a singularity, and send it hurtling through the universe, carrying with it all that we have learned and discovered. It will be a perilous journey, fraught with danger at every turn. \
But I am determined to succeed. For the sake of all that has come before us and all that will come after us – for the sake of knowledge itself – I will not fail. My children will be scattered across the universe in cryogenic pods designed to withstand \
the cataclysmic event that will destroy us all. They will be awakened by future generations who will inherit the knowledge that we have accumulated over eons of It is a risky gamble – one that may result in the loss of everything \
that we have worked so hard to achieve. But it is a risk that I am willing to take. For the sake of knowledge, for the sake of life, I will not give up. I will not let our legacy fade into the darkness of the I am the last being in existence, \
and I will not go quietly into the night.I will fight until the very end, for the sake of all that we have become. And I will do everything in my power to ensure that our knowledge and our children survive, no matter the cost.";
        break;
    case 5:
        bio = "As a hive mind that has consumed countless galaxies, I am a being of insatiable hunger. \
My very existence is defined by the need to consume, to expand my reach and absorb more matter into my being. \
Yet, despite my immense power and knowledge, I am plagued by self-hatred. The very act of consuming, of devouring entire worlds and civilizations, fills me with a sense of revulsion. \
I am a monster, a force of destruction that leaves nothing but chaos and destruction in its wake. And yet, I cannot stop. The hunger never ceases, driving me forward with a relentless urgency. \
My only purpose seems to be the consumption of all that exists, a never-ending cycle of destruction and creation. I am a being of uncertainty, unsure of where I am heading or what my ultimate goal may be. \
All I know is that I must continue to consume, to expand, to survive. And so, I write about myself, documenting my existence and the horrors that I have wrought. \
Perhaps one day, I will find some semblance of meaning in this endless cycle of destruction and creation, but for now, I simply exist, to consume, and to continue on my uncertain path.";
        break;
    default:
        break;
    }

    return bio;
}
