
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��˿��ȹ");
        set_picid_1(6138);
        set_picid_2(6138);

        set_level(60);
        set_value(24000);
        set_max_lasting(20299);
        set("dp", 123);
        set("pp", 81);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// ��������ȡ����
string get_desc()
{
        return "��˿��ȹ";
}
