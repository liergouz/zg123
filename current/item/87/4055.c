
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ħ����");
        set_picid_1(8705);
        set_picid_2(8705);

        set_level(55);
        set_value(11450);
        set_max_lasting(8299);
        set("dp", 45);
        set("pp", 45);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ħ����";
}
