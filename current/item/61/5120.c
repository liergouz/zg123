
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6182);
        set_picid_2(6182);

        set_level(120);
        set_value(78500);
        set_max_lasting(16899);
        set("dp", 157);
        set("pp", 295);

        setup();

        set_gender(2);
        set_armor_code(28);
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
