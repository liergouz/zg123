
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6082);
        set_picid_2(6082);

        set_level(100);
        set_value(62500);
        set_max_lasting(14499);
        set("dp", 136);
        set("pp", 250);

        setup();

        set_gender(1);
        set_armor_code(7);
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
