
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��¶����");
        set_picid_1(8652);
        set_picid_2(8652);

        set_level(60);
        set_value(34500);
        set_max_lasting(7899);
        set("cp", 0);
        set("pp", 65);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��¶����";
}
