
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��ͷ����");
        set_picid_1(8705);
        set_picid_2(8705);

        set_level(50);
        set_value(15000);
        set_max_lasting(6199);
        set("dp", 35);
        set("pp", 50);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ͷ����";
}
