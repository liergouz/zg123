
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��ˮ����");
        set_picid_1(8709);
        set_picid_2(8709);

        set_level(45);
        set_value(13250);
        set_max_lasting(6099);
        set("dp", 32);
        set("pp", 45);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ˮ����";
}
