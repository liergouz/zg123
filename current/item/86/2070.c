
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(70);
        set_value(41500);
        set_max_lasting(8199);
        set("cp", 0);
        set("pp", 75);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
