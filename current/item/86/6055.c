
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("����֮��");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(55);
        set_value(39500);
        set_max_lasting(5399);
        set("cp", 100);
        set("pp", 60);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����֮��";
}
