
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8652);
        set_picid_2(8652);

        set_level(90);
        set_value(55500);
        set_max_lasting(8799);
        set("cp", 0);
        set("pp", 85);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
