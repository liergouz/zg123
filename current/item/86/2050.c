
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("����֮��");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(50);
        set_value(27500);
        set_max_lasting(7599);
        set("cp", 0);
        set("pp", 55);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����֮��";
}
