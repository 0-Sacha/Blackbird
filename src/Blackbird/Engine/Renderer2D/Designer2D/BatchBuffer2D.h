#pragma once

#include "Blackbird/Core/Core.h"

namespace Blackbird
{
    template <typename ObjectVertexType, std::size_t VERTICIES_PER_OBJECT, std::size_t INDICIES_PER_OBJECT>
    class BatchBuffer2D
    {
	public:
        BatchBuffer2D(std::size_t maxCount)
        {
            ResizeAndReset(maxCount);
        }

	public:
		static constexpr std::size_t GetVerticiesPerObject()    { return VERTICIES_PER_OBJECT; }
		static constexpr std::size_t GetIndiciesPerObject()     { return INDICIES_PER_OBJECT; }

		std::size_t GetMaxCount() const { return m_MaxCount; }
		std::size_t GetMaxIndicies() const { return m_MaxCount * INDICIES_PER_OBJECT; }
		std::size_t GetMaxVerticies() const { return m_MaxCount * VERTICIES_PER_OBJECT; }

		const ObjectVertexType* GetData() const     { return m_Buffer.get(); }

		std::size_t GetObjectCount() const          { return m_ObjectCount; }
		std::size_t GetIndiciesCount() const        { return m_ObjectCount * INDICIES_PER_OBJECT; }
        std::size_t GetVerticiesSize() const        { return GetVerticieCount() * sizeof(ObjectVertexType); }

		std::size_t GetVerticieCount() const
        {
            BLACKBIRD_ASSERT((m_BufferCurrentPos - m_Buffer.get()) == (m_ObjectCount * VERTICIES_PER_OBJECT), "Wrong number of verticies compared to the number of objects")
            return m_BufferCurrentPos - m_Buffer.get();
        }

	public:
		void BeginScene()
        {
			m_BufferCurrentPos = m_Buffer.get();
            m_ObjectCount = 0;
		}

		bool CanPushBack() { return m_BufferCurrentPos + 1 < m_BufferEnd; }
		bool CanPushBack(std::size_t count) { return m_BufferCurrentPos + count < m_BufferEnd; }

		void PushBackVertex(const ObjectVertexType& object)
        {
            BLACKBIRD_ASSERT(CanPushBack(), "Can't PushBack a Verex in the BatchBuffer")
            *m_BufferCurrentPos++ = object;
        }

        void ObjectAdded() { m_ObjectCount++; }

    protected:
		void ResizeAndReset(std::size_t maxCount)
        {
            m_MaxCount = maxCount;
            m_Buffer.reset(new ObjectVertexType[GetMaxVerticies()]);
            m_BufferEnd = m_Buffer.get() + m_MaxCount * sizeof(ObjectVertexType);
            m_BufferCurrentPos = m_Buffer.get();
        }

    protected:
		std::size_t m_MaxCount = 0;
		
        std::size_t m_ObjectCount = 0;

        std::unique_ptr<ObjectVertexType[]> m_Buffer = nullptr;
		ObjectVertexType* m_BufferEnd = nullptr;
		ObjectVertexType* m_BufferCurrentPos = nullptr;
    };
}
