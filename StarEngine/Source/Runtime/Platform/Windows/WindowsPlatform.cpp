#include"starpch.h"
#include"WindowsPlatform.h"

namespace Star
{
Platform* Platform::Create()
{
    return new WindowsPlatform();
}


}// namespace Star