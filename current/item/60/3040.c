
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�Ƶ���");
        set_picid_1(6056);
        set_picid_2(6056);

        set_level(40);
        set_value(12500);
        set_max_lasting(13599);
        set("dp", 104);
        set("pp", 58);

        setup();

        set_gender(1);
        set_armor_code(3);
}

// ��������ȡ����
string get_desc()
{
        return "�Ƶ���";
}
