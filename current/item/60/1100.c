
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6082);
        set_picid_2(6082);

        set_level(100);
        set_value(57500);
        set_max_lasting(31599);
        set("dp", 231);
        set("pp", 144);

        setup();

        set_gender(1);
        set_armor_code(7);
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
