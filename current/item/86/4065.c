
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8657);
        set_picid_2(8657);

        set_level(65);
        set_value(42100);
        set_max_lasting(6799);
        set("cp", 0);
        set("pp", 67);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
