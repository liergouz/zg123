
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 1334; }

// ���������촦��
void create()
{
        set_name("�¹�����");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(40);
        set_value(20000);
        set_max_lasting(7099);
        set("ap", 0);
        set("dp", 0);
        set("cp", 85);
        set("pp", 58);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�¹�����";
}
